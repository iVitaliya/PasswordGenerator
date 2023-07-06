import * as readline from "readline";

const chars: string[] = [];

function main() {
    const rl: readline.Interface = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question("\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)\n", (other: string) => {
        addChars(chars, other);

        rl.question("\nHow long would you like your password to be? (1-30)\n", (lenStr: string) => {
            const len: number = parseInt(lenStr, 10);

            if (!isNaN(len)) {
                console.log(`\n\nHere's your new password: ${generatePassword(len)}`)
            }

            rl.close();
        });
    });
}

function generatePassword(length): string {
    let password: string = "";
    let j: number = 0;

    while (j < length) {
        const randomIndex: number = Math.floor(Math.random() * chars.length);
        password += chars[randomIndex];
        j++;
    }

    return password;
}

function addChars(chars: string[], additionals: string) {
    for (let c: number = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); c++) {
        chars.push(String.fromCharCode(c));
    }

    for (let c: number = 'A'.charCodeAt(0); c <= 'Z'.charCodeAt(0); c++) {
        chars.push(String.fromCharCode(c));
    }

    switch (additionals) {
        case '1':
            for (let c: number = '!'.charCodeAt(0); c <= '?'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;
        
        case '2':
            for (let c: number = '0'.charCodeAt(0); c <= '9'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;
    
        case '3':
            for (let c: number = '!'.charCodeAt(0); c <= '?'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            for (let c: number = '0'.charCodeAt(0); c <= '9'.charCodeAt(0); c++) {
                chars.push(String.fromCharCode(c));
            }
            break;

        default:
            console.log("\nYour choice didn't meet any of the given choices so I didn't add any special/numberic characters");
            break;
    }
}

main();