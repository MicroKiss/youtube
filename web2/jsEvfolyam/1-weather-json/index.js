const textarea = document.querySelector('#the-textarea');
const button = document.querySelector('#the-button');
const task1 = document.querySelector('#task1')
const task2 = document.querySelector('#task2')
const task3 = document.querySelector('#task3')
const task4 = document.querySelector('#task4')
const task5 = document.querySelector('#task5')


//a
const obj = JSON.parse(textarea.value)
console.log(obj);
//b
task1Day = obj["daily"].find((day) => {
	if (day["wind_deg"] >= 135 && day["wind_deg"] <= 225 && day["weather"][0]["main"] === "Clouds")
		return true;
	return false;
})
task1.innerHTML = task1Day["dt"];
//c

task2Day = obj["daily"].reduce((prev, curr) => {
	return prev["temp"]["max"] < curr["temp"]["max"] ? prev : curr;
})
task2.innerHTML = task2Day["temp"]["max"];
//d
task3Answer = obj["daily"].every((day) => {
	return day["pressure"] > 1010;
})
task3.innerHTML = task3Answer;
//e 

task4Sum = obj["daily"].reduce((prev, curr) => {
	return prev += curr["feels_like"]["day"];
}, 0)
task4.innerHTML = task4Sum / obj["daily"].length;

//f
task5.innerHTML = obj["hourly"].filter((h) => {
	return h["wind_speed"] > 3;
}).length;