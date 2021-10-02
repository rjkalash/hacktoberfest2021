const setButton = document.querySelector("#set");
const stopButton = document.querySelector("#stop");
const testButton = document.querySelector("#test");
const alert_div = document.querySelector("#inner-alert-text");
const clock = document.querySelector("#clock");
const audio = new Audio("https://www.soundjay.com/buttons/beep-01a.wav");
//!Domslider Hour and Hour Input
var Input_Hours = 0;
const add = document.querySelector("#add-hour");
const sub = document.querySelector("#sub-hour");
const display = document.querySelector("#display");

add.addEventListener('click', hourAdd);

function hourAdd() {
    if (Input_Hours == 24) {
        console.log(" are you a fucking mad");
    } else {
        console.log("add");
        Input_Hours++;
        display.innerHTML = Input_Hours;
    }
}

sub.addEventListener('click', subHour);

function subHour() {
    if (Input_Hours == 0) {
        console.log("are you a fucking idiot");
    } else {

        console.log("sub");
        Input_Hours--;
        display.innerHTML = Input_Hours;
    }
}
//!Domslider-minute
min = 0;
const add_minutes = document.querySelector("#add-minutes");
const sub_minutes = document.querySelector("#sub-minutes");
const display_minutes = document.querySelector("#display-minutes");

add_minutes.addEventListener('click', minutesAdd);

function minutesAdd() {
    if (min == 59) {
        console.log(" are you a fucking mad");
    } else {
        console.log("add");
        min++;
        display_minutes.innerHTML = min;
    }
}

sub_minutes.addEventListener('click', subMinutes);

function subMinutes() {
    if (min == 0) {
        console.log("are you a fucking idiot");
    } else {

        console.log("sub");
        min--;
        display_minutes.innerHTML = min;
    }
}
//!function clock
var timeout = 1000;
// ? clock function
function clockUpdate() {
    d = new Date();
    hours = d.getHours();
    minutes = d.getMinutes();
    seconds = d.getSeconds();
    //! add "0" 
    clockMinutes = minutes;
    clockMinutes = minutes < 10 ? "0" + minutes : clockMinutes;

    //
    clockSeconds = seconds;
    clockSeconds = seconds < 10 ? "0" + seconds : clockSeconds;

    //
    clockHours = hours;
    clockHours = hours < 10 ? "0" + hours : clockHours;

    clock.innerHTML = clockHours + ":" + clockMinutes + ":" + clockSeconds;
    clockTime = setTimeout(clockUpdate, 1000);
}
//!alarm function declartion
setButton.addEventListener("click", Alarm);
stopButton.addEventListener("click", stopAlarm);
clockUpdate();
// ? stop alarm
function stopAlarm() {
    timeout = timeout + 60000;
}
//? alarm-listner
function Alarm() {
    setHours = Input_Hours;
    setMinutes = min;
    timeout = 1000;
    alert_div.innerHTML = `alarm set for ${setHours}:${setMinutes}  <button id="close-alert">close</button>`;
    //?function-alarm-set and check
    const close_alert = document.querySelector("#close-alert");
    close_alert.addEventListener('click', hideAlert);

    function hideAlert() {
        alert_div.innerHTML = null;
    }

    function setAlarm() {
        if (setHours == hours) {
            if (setMinutes == minutes) {
                play();
                console.log(true);
            } else {
                console.log("false");
            }
        }
        //?funtion play-on-call
        function play() {
            audio.play();
            alert_div.innerHTML = null;
        }
        //? timeout-var
        z = setTimeout(setAlarm, timeout);
    }
    setAlarm();
}

//  ?end of alarm listener
