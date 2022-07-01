{
    "targets": [{
        "target_name": "addon",
        "sources": ["addon.min.cc"],
        "cflags!": ["-fno-exceptions"],
        "cflags_cc!": ["-fno-exceptions"],
        "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
        "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
        "conditions": [
            ["OS==\"win\"", {
                "msvs_settings": {
                    "VCCLCompilerTool": {
                        "ExceptionHandling": 1
                    }
                }
            }]
        ]
    }]
}