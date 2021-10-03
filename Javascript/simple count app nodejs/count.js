const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const question = (query) =>
  new Promise((resolve) => rl.question(query, resolve));

const tambah = (a, b) => {
  return a + b;
};

const perkalian = (a, b) => {
  return a * b;
};

const pembagian = (a, b) => {
  return a / b;
};

const pengurangan = (a, b) => {
  return a - b;
};

module.exports = { tambah, question, rl, perkalian, pembagian, pengurangan };
