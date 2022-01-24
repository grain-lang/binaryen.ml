// Attach binaryen to globalThis because JSOO wraps in an iife
globalThis.binaryen = module.exports;
