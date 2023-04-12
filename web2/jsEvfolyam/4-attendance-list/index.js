const table = document.querySelector('table');

function xyCoord(td) {
  return {
    x: td.cellIndex,
    y: td.parentNode.sectionRowIndex,
  }
}

function delegate(parent, type, selector, handler) {
  parent.addEventListener(type, function (event) {
    const targetElement = event.target.closest(selector);

    if (this.contains(targetElement)) {
      handler.call(targetElement, event);
    }
  });
}

//a
function SetPresents() {
  const cells = table.getElementsByTagName('td');

  for (const cell of cells) {
    let checkBox = cell.getElementsByTagName('input')[0];
    if (!checkBox)
      continue;
    if (checkBox.checked)
      cell.classList.add('present')
    else
      cell.classList.remove('present')
  }
}

SetPresents();

//b

delegate(table, 'click', 'td', (event) => {
  let checkBox = event.target.getElementsByTagName('input')[0];
  if (checkBox) {
    checkBox.focus();
  }
})

//c
delegate(table, 'click', 'input', (event) => {
  SetPresents();
})

//def
document.addEventListener('keydown', (event) => {
  if (document.activeElement.tagName !== 'INPUT')
    return;
  let newCoords = xyCoord(document.activeElement.parentElement);
  let x = newCoords.x;
  let y = newCoords.y;
  switch (event.key) {
    case 'ArrowRight':
      newCoords.x++;
      break;
    case 'ArrowLeft':
      newCoords.x--;
      break;
    case 'ArrowUp':
      newCoords.y--;
      break;
    case 'ArrowDown':
      newCoords.y++;
      break;
    default:
      return;
  }
  console.log(x, y);
  if (newCoords.x < 1)
    newCoords.x = 7
  else if (newCoords.x > 7)
    newCoords.x = 1

  if (newCoords.y < 0)
    newCoords.y = 2
  else if (newCoords.y > 2)
    newCoords.y = 0

  let td = table.rows[newCoords.y + 1].cells[newCoords.x];
  let checkBox = td.getElementsByTagName('input')[0];
  checkBox.focus();
})