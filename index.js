const addon = require(`./build/Release/addon.node`);
/**
* Method to check the internet connection.
* @returns {Boolean}
*/
module.exports.get = addon.GetConnectivity;