document.addEventListener('DOMContentLoaded',function(event){

    var dataText = [ "Hello, This is Typing Animation","It is Awesome.", "It uses HTML.", "It uses CSS.", "It uses JavaScript."];
   
    function typeWriter(text, i, fnCallback) {
    
      if (i < (text.length)) {
   
       document.querySelector("h1").innerHTML = text.substring(0, i+1) +'<span aria-hidden="true"></span>';
  
   
        setTimeout(function() {
          typeWriter(text, i + 1, fnCallback)
        }, 100);
      }
    
      else if (typeof fnCallback == 'function') {
      
        setTimeout(fnCallback, 700);
      }
    }
  
     function StartTextAnimation(i) {
       if (typeof dataText[i] == 'undefined'){
          setTimeout(function() {
            StartTextAnimation(0);
          }, 20000);
       }
  
      if (i < dataText[i].length) {
      
       typeWriter(dataText[i], 0, function(){
    
         StartTextAnimation(i + 1);
       });
      }
    }
    StartTextAnimation(0);
  });