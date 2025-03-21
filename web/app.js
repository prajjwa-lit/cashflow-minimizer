let Module = {
    onRuntimeInitialized: function () {
        console.log("WebAssembly Loaded!");
    }
};

function runMinimizer() {
    let input = document.getElementById("input").value;
    let result = Module.ccall("minimizeCashFlow", "string", ["string"], [input]);
    document.getElementById("output").innerText = result;
}
