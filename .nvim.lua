local dap = require('dap')

local function get_tests_directory()
    local problem_number = vim.fn.expand('%:p:t'):sub(1, 1)
    local tests_dir = vim.fn.expand('%:p:h') .. "/tests/" .. problem_number
    return tests_dir
end

local function select_file_in_directory(directory)
    local files = vim.fn.readdir(directory)
    local file_list = {}

    for _, file in ipairs(files) do
        local full_path = directory .. "/" .. file
        if vim.fn.isdirectory(full_path) == 0 and file:sub(1, 2) == "be" then
            table.insert(file_list, file)
        end
    end

    if #file_list == 0 then
        print("No matching files found in " .. directory)
        return
    end

    local numbered_list = {}
    for i, file in ipairs(file_list) do
        table.insert(numbered_list, string.format("%d: %s", i, file))
    end

    local file_index = vim.fn.inputlist(numbered_list)
    if file_index <= 0 or file_index > #file_list then
        print("Invalid selection")
        return
    end

    return directory .. "/" .. file_list[file_index]
end

dap.configurations.cpp = {
    {
        name = "Launch NemesOnline",
        type = "cppdbg",
        request = "launch",
        program = function()
            vim.cmd('!g++ ' .. vim.fn.expand('%') .. ' -o bin/a -g')
            return 'bin/a'
        end,
        cwd = '${workspaceFolder}',
        stopAtEntry = false,
        args = function()

            local tests_dir = get_tests_directory();
            local input_file = select_file_in_directory(tests_dir)
            return {'<', input_file}
        end,
        setupCommands = {
            {
                text = '-enable-pretty-printing',
                description =  'enable pretty printing',
                ignoreFailures = false
            },
        },
    },
}
