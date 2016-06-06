import qbs 1.0

Application {
    name: "dijkstra"
    consoleApplication: true

    Depends { name: "cpp" }
    cpp.cxxLanguageVersion: "c++11"

    files: [
        "*.h",
        "*.cpp"
    ]
}
