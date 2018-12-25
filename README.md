# Auara_project for the development of solar water pumps  (IMH Elgoibar)


700 Million people lack adequate access to safe water.

## Table of Contents

* [Read this first](#read-this-first)
* [Usage](#usage)
  * [License and acknowledgement](#license)
    * [Electrical diagram](#electrical-diagram)
    * [Mechanical 3D design](#mechanical-3d-design)
    * [Microcontroller firmware](#microcontroller-firmware)
* [Browser Support](#browser-support)

## Read this first

*In drought-affected areas of Kenya, women must walk miles to find water, risking violence or animal 
attack, in order to sustain their families and animals. They do this with the knowledge that the dirty 
water they have collected may well make their children very ill.

Using the overabundance of sunshine, the solar pump draws water from a 100-metre-deep well, providing 
families with the water that they desperately need and rendering cases of water-related diseases a 
thing of the past.

* If you have an idea for a new feature, **submit your feature
  requests** to the [specification's repository](https://github.com/iarakistain/Auara_project/issues).
  

## Usage

For a more comprehensive reference, refer to
https://github.com/iarakistain/Auara_project

### License and acknowledgement

This project is released as Open Source, with Creative Commons, 
Share Alike license. Feel free to modify and improve it. Commercial
use is not allowed. 

In case you use it, please acknowleded IMH Institute. 


#### Electrical diagram

To have `fetch` Promise reject on HTTP error statuses, i.e. on any non-2xx
status, define a custom response handler:

```javascript
function checkStatus(response) {
  if (response.status >= 200 && response.status < 300) {
    return response
  } else {
    var error = new Error(response.statusText)
    error.response = response
    throw error
  }
}

function parseJSON(response) {
  return response.json()
}

fetch('/users')
  .then(checkStatus)
  .then(parseJSON)
  .then(function(data) {
    console.log('request succeeded with JSON response', data)
  }).catch(function(error) {
    console.log('request failed', error)
  })
```

#### Mechanical 3D design

For [CORS][] requests, use `credentials: 'include'` to allow sending credentials
to other domains:

```javascript
fetch('https://example.com:1234/users', {
  credentials: 'include'
})
```

To disable sending or receiving cookies for requests to any domain, including
the current one, use the "omit" value:

```javascript
fetch('/users', {
  credentials: 'omit'
})
```

The default value for `credentials` is "same-origin".

The default for `credentials` wasn't always the same, though. The following
versions of browsers implemented an older version of the fetch specification
where the default was "omit":

* Firefox 39-60
* Chrome 42-67
* Safari 10.1-11.1.2

If you target these browsers, it's advisable to always specify `credentials:
'same-origin'` explicitly with all fetch requests instead of relying on the
default:

```javascript
fetch('/users', {
  credentials: 'same-origin'
})
```

#### Microcontroller firmware

As with XMLHttpRequest, the `Set-Cookie` response header returned from the
server is a [forbidden header name][] and therefore can't be programmatically
read with `response.headers.get()`. Instead, it's the browser's responsibility
to handle new cookies being set (if applicable to the current URL). Unless they
are HTTP-only, new cookies will be available through `document.cookie`.



## Browser Support

- Chrome
- Firefox
- Safari 6.1+
- Internet Explorer 10+

Note: modern browsers such as Chrome, Firefox, Microsoft Edge, and Safari contain native
implementations of `window.fetch`, therefore the code from this polyfill doesn't
have any effect on those browsers. If you believe you've encountered an error
with how `window.fetch` is implemented in any of these browsers, you should file
an issue with that browser vendor instead of this project.


  [fetch specification]: https://fetch.spec.whatwg.org
  [cors]: https://developer.mozilla.org/en-US/docs/Web/HTTP/Access_control_CORS
    "Cross-origin resource sharing"
  [csrf]: https://www.owasp.org/index.php/Cross-Site_Request_Forgery_(CSRF)_Prevention_Cheat_Sheet
    "Cross-site request forgery"
  [forbidden header name]: https://developer.mozilla.org/en-US/docs/Glossary/Forbidden_header_name
  [releases]: https://github.com/github/fetch/releases
