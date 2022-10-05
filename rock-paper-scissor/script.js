const playerText = document.querySelector("#playerText");
const computerText = document.querySelector("#computerText");
const resultText = document.querySelector("#resultText");
const choiceBtns = document.querySelectorAll(".choiceBtn");

let player;
let computer;
let result;

choiceBtns.forEach((button) =>
  button.addEventListener("click", function () {
    player = button.textContent;

    computerTurn();

    playerText.textContent = `Player: ${player}`;
    computerText.textContent = `Computer: ${computer}`;
    resultText.textContent = checkWinner();
  })
);

function computerTurn() {
  const ranNum = Math.floor(Math.random() * 3) + 1;

  switch (ranNum) {
    case 1:
      computer = "Rock";
      break;

    case 2:
      computer = "Paper";
      break;

    case 3:
      computer = "Scissor";
      break;
  }
}

function checkWinner() {
  if (player == computer) {
    return "Draw!!";
  } else if (computer == "Rock") {
    return player == "Paper" ? "You Win!!" : "You Loose!!";
  } else if (computer == "Paper") {
    return player == "Scissor" ? "You Win!!" : "You Loose!!";
  } else if (computer == "Scissor") {
    return player == "Rock" ? "You Win!!" : "You Loose!!";
  }
}
