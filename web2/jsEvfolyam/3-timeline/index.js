const animButton = document.querySelector('#animation');
const leftButton = document.querySelector('#left');
const rightButton = document.querySelector('#right');
const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

let pixelsPerYear = 5;
let origoYear = 1000;
let dt = 0.2;

function GetX(year) {
	return (year - origoYear) * pixelsPerYear;
}


function ReDraw() {
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	//a
	ctx.strokeStyle = 'red';
	ctx.fillStyle = 'black';
	for (let y = 1000; y <= 1500; y += 50) {
		ctx.beginPath();
		ctx.moveTo(GetX(y), 0);
		ctx.lineTo(GetX(y), canvas.height);
		ctx.stroke();
		ctx.fillText(y, GetX(y), 10);
	}

	//b


	ctx.strokeStyle = 'black';
	for (const king of arpads) {
		ctx.fillStyle = 'green';
		ctx.beginPath();
		let width = (GetX(king["to"]) - GetX(king["from"])) * pixelsPerYear;
		ctx.rect(GetX(king["from"]), 60, width, 60);
		ctx.fill();
		ctx.stroke();
		ctx.fillStyle = 'black';
		ctx.fillText(king["name"], GetX(king["from"]) + 2, 70);
		ctx.fillText(king["from"] + '-' + king["to"], GetX(king["from"]) + 2, 80);
	}


	//cd

	for (const king of plantanegets) {
		ctx.fillStyle = 'red';
		ctx.strokeStyle = 'black';
		ctx.beginPath();
		let width = (GetX(king["to"]) - GetX(king["from"])) * pixelsPerYear;
		ctx.rect(GetX(king["from"]), 150, width, 60);
		ctx.fill();
		ctx.stroke();
		ctx.fillStyle = 'black';
		ctx.fillText(king["name"], GetX(king["from"]) + 2, 160);
		ctx.fillText(king["from"] + '-' + king["to"], GetX(king["from"]) + 2, 170);
	}
}

ReDraw();
//e
leftButton.onclick = () => {
	origoYear -= 10;
	ReDraw();
}

//f
rightButton.onclick = () => {
	origoYear += 10;
	ReDraw();
}

//g

var animID = undefined;
function Anim() {
	origoYear += dt;
	ReDraw();
	animID = window.requestAnimationFrame(Anim);
}

animButton.onclick = () => {
	if (animID) {
		cancelAnimationFrame(animID);
		animID = undefined;
	} else {
		Anim();
	}
}