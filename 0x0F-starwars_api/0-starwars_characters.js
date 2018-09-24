#!/usr/bin/node
// prints all characters of a Star Wars movie
const request = require('request');

let all = new Map();
let count = 0;
let options = {
  url: 'https://swapi.co/api/films/' + process.argv[2],
  headers: {
    'format': 'json'
  }
};
function callback (error, response, body) {
  if (!error && response.statusCode === 200) {
    let res = JSON.parse(body);
    let lim = Object.keys(res['characters']).length;
    for (let i in res['characters']) {
      request(res['characters'][i], function (error, response, body) {
        count++;
        if (error) { console.log(error); } else {
          all.set(i, JSON.parse(body)['name']);
        }
        if (count === lim) {
          for (let j = 0; j < lim; j++) {
            console.log(all.get(j.toString()));
          }
        }
      });
    }
  }
}
