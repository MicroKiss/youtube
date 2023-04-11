const filters = [
  { label: 'Blur', filter: 'blur(#px)', min: 0, max: 10, value: 3 },
  { label: 'Brightness', filter: 'brightness(#%)', min: 0, max: 500, value: 80 },
  { label: 'Contrast', filter: 'contrast(#%)', min: 0, max: 500, value: 200 },
  { label: 'Grayscale', filter: 'grayscale(#%)', min: 0, max: 100, value: 50 },
  { label: 'Hue rotate', filter: 'hue-rotate(#deg)', min: 0, max: 360, value: 90 },
  { label: 'Invert', filter: 'invert(#%)', min: 0, max: 100, value: 80 },
  { label: 'Opacity', filter: 'opacity(#%)', min: 0, max: 100, value: 50 },
  { label: 'Saturate', filter: 'saturate(#%)', min: 0, max: 500, value: 200 },
  { label: 'Sepia', filter: 'sepia(#%)', min: 0, max: 100, value: 50 },
];

const theFiltersDiv = document.querySelector('#the-filters')
const theImage = document.querySelector('#the-image')

//a-d
const filterLabels = theFiltersDiv.getElementsByTagName('label');

function ChangeStyle() {
  let filtercss = '';
  for (const label of filterLabels) {
    let inputs = label.getElementsByTagName('input');
    let checkBox = inputs[0];
    let range = inputs[1];
    if (checkBox.checked) {
      let currentFilter = checkBox.value.replace('#', range.value);
      filtercss += currentFilter + ' '
    }
  }
  theImage.style.cssText = 'filter: ' + filtercss;
}

theFiltersDiv.addEventListener('input', ChangeStyle);
//e
let generatedFilters = '';

for (const filter of filters) {
  generatedFilters += `
<label>
<input type="checkbox" value="${filter["filter"]}">
${filter["label"]}
<input type="range" min="${filter["min"]}" max="${filter["max"]}" value="${filter["value"]}">
</label>
`
}



theFiltersDiv.innerHTML = generatedFilters;