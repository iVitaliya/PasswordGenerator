import flash.system.fscommand;

var chars:Array = [];

function main():void {
    var other:String = fscommand("Which other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)");

    addChars(chars, other);

    var lenStr:String = fscommand("How long would you like your password to be? (1-30)");
    var len:int = parseInt(lenStr, 10);

    if (!isNaN(len)) {
        trace("\n\nHere's your new password: " + generatePassword(len));
    }
}

function generatePassword(length:int):String {
    var password:String = "";
    var j:int = 0;

    while (j < length) {
        var randomIndex:int = Math.floor(Math.random() * chars.length);
        password += chars[randomIndex];
        j++;
    }

    return password;
}

function addChars(chars:Array, additionals:String):void {
    for (var c:int = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); c++) {
        chars.push(String.fromCharCode(c));
    }

    for (c = 'A'.charCodeAt(0); c <= 'Z'.charCodeAt(0); c++) {
        chars.push(String.fromCharCode(c));
    }

    switch (additionals) {
        case '1':
            for (c = '!'.charCodeAt(0); c <= '?'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;

        case '2':
            for (c = '0'.charCodeAt(0); c <= '9'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;

        case '3':
            for (c = '!'.charCodeAt(0); c <= '?'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            for (c = '0'.charCodeAt(0); c <= '9'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;

        default:
            trace("\nYour choice didn't meet any of the given choices so I didn't add any special/numeric characters");
            break;
    }
}

main();