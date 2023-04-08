var c1 = document.getElementById('c1');
var c2 = document.getElementById('c2');
var ctx1 = c1.getContext('2d');
var ctx2 = c2.getContext('2d');

var scratching = false;
var done = false;
ctx1.textAlign = 'center';

function Init() {
	done = false;
	ctx1.clearRect(0, 0, c1.width, c1.height);
	ctx1.font = '48px serif'
	if (Math.random() < .5) {
		ctx1.fillStyle = 'green';
		ctx1.fillText("You won", c1.width / 2, c1.height / 2);
	} else {
		ctx1.fillStyle = 'red';
		ctx1.fillText("You lose", c1.width / 2, c1.height / 2);
	}

	ctx2.fillStyle = 'gray';
	ctx2.fillRect(0, 0, c2.width, c2.height);
}

c2.addEventListener('mousedown', (event) => {
	scratching = true;
})

c2.addEventListener('mouseup', (event) => {
	scratching = false;
})

c2.addEventListener('mousemove', (event) => {
	if (!scratching) return;
	let bx = event.target.getBoundingClientRect();
	let r = 20;
	ctx2.clearRect(event.clientX - bx.left - r / 2, event.clientY - bx.top - r / 2, r, r);
	Check();
})

addEventListener('keydown', (event) => {
	if (done && event.key == 'r')
		Init();
})

function Check() {
	const imageData = ctx2.getImageData(c2.width / 3, c2.height / 3, c2.width / 3, c2.height / 3);
	let strachedPixel = 0;
	for (let index = 0; index < imageData.data.length; index += 4) {

		if (imageData.data[index + 3] == 0)
			strachedPixel++;
	}
	if ((strachedPixel / (imageData.data.length / 4)) > .9) {
		done = true;
		ctx1.font = '24px serif';
		ctx1.fillStyle = 'black';
		ctx1.fillText("Press R to strach again!", c1.width / 2, c1.height / 3 * 2);
	}
}


Init();