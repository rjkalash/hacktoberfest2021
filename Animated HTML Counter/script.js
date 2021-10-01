setInterval(function () {
  doFlip(3);
}, 1000);

function doFlip(numberIndex) {
  var currentNumberElement = $('.number:eq(' + numberIndex + ')');

  var currentNumber = Number(currentNumberElement.attr('data-number'));

  currentNumber++;

  if (currentNumber > 9) {
    currentNumber = 0;

    if (numberIndex > 0) {
      doFlip(--numberIndex);
    }
  }

  currentNumberElement.addClass('flip');

  setTimeout(function () {
    currentNumberElement.attr('data-number', currentNumber);

    currentNumberElement.removeClass('flip');
  }, 500);
}
