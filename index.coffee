readline = require("readline")

chars = []

main = ->
    rl = readline.createInterface
        input: process.stdin
        output: process.stdout
    
    rl.question "\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)\n", (other) ->
        addChars chars, other

        rl.question "\nHow long would you like your password to be? (1-30)\n", (lenStr) ->
            len = parseInt lenStr, 10

            if not isNaN len
                console.log "\n\nHere's your new password: #{generatePassword len}"
            
            rl.close()

generatePassword = (length) ->
    password = ""
    j = 0

    while j < length
        randomIndex = Math.floor(Math.random() * chars.length)
        password += chars[randomIndex]
        j++
    
    password

addChars = (chars, additionals) ->
  for c in ['a'.charCodeAt(0).. 'z'.charCodeAt(0)]
    chars.push String.fromCharCode(c)

  for c in ['A'.charCodeAt(0).. 'Z'.charCodeAt(0)]
    chars.push String.fromCharCode(c)

  switch additionals
    when '1'
      for c in ['!'.charCodeAt(0).. '?'.charCodeAt(0)]
        chars.push String.fromCharCode(c)
    when '2'
      for c in ['0'.charCodeAt(0).. '9'.charCodeAt(0)]
        chars.push String.fromCharCode(c)
    when '3'
      for c in ['!'.charCodeAt(0).. '?'.charCodeAt(0)]
        chars.push String.fromCharCode(c)
      for c in ['0'.charCodeAt(0).. '9'.charCodeAt(0)]
        chars.push String.fromCharCode(c)
    else
      console.log "\nYour choice didn't meet any of the given choices so I didn't add any special/numeric characters"

main()