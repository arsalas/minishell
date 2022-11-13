
const prompt = document.querySelector('.prompt input')
const result = document.querySelector('#result')
const videoCont = document.querySelector('#video')
const video = document.querySelector('video')

const history = {
    cmd: [],
    index: 0
}


const handleSubmit = (e) => {
    e.preventDefault();
    const parse = parseInput(prompt.value.trim());
    if (!parse) return;
    history.cmd.push(prompt.value)
    history.index = history.cmd.length
    executeCommand(parse);
    prompt.value = ''

}



const parseInput = (input) => {
    if (input.length == 0) return;
    const parse = input.split(' ');
    const data = {
        command: parse.splice(0, 1)[0],
        args: parse.join(' ')
    }
    return data
}

const executeCommand = (cmd) => {
    result.style.color = ''
    if (cmd.command == 'echo') {
        echo(cmd.args)
        return;
    }
    if (cmd.command == 'pwd') {
        echo(window.location.href)
        return;
    }
    if (cmd.command == 'authors') {
        echo("amurcia- && aramirez")
        return;
    }
    if (cmd.command == 'man') {
        echo("You can use echo, pwd, grademe, authors, demo")
        return;
    }
    if (cmd.command == 'grademe') {
        result.style.color = 'green'
        echo("100/100")
        return;
    }
    if (cmd.command == 'demo') {
        videoCont.style.display = 'block'
        video.play();
        return;
    }
    echo(`command: ${cmd.command} not found`)
    return;

}

const echo = (content) => {
    result.innerHTML = content

}

const handleKey = (e) => {
    if (e.keyCode == 38 && history.index > 0) {
        history.index--;
        prompt.value = history.cmd[history.index]
        return
    }
    if (e.keyCode == 40 && history.index < history.cmd.length - 1) {
        history.index++;
        prompt.value = history.cmd[history.index]
        return;
    }
}

document.querySelector('form').addEventListener('submit', handleSubmit)
prompt.addEventListener('keyup', handleKey)