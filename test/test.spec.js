const { get_mime_type } = require('../lib')


const types = [
  'text/plain', 'text/css', 'text/html', 'text/html', 'image/png', 'image/jpeg', 'image/jpeg',
  'image/svg+xml', 'image/gif', 'image/webp', 'image/x-icon', 'application/javascript',
  'application/json', 'application/json', 'application/pdf', 'text/xml', 'application/x-yaml',
  'application/zip', 'application/gzip', 'application/tar', 'application/tar+gzip',
  'application/tar+gzip', 'audio/mp4', 'audio/aac', 'audio/mp3', 'audio/wav', 'video/mpeg',
  'video/mpeg', 'video/ogg', 'video/ogg', 'video/mp4', 'video/mp4', 'video/webm'
]

const extensions = [
  '.txt', '.css', '.htm', '.html', '.png', '.jpeg', '.jpg', '.svg', '.gif', '.webp', '.ico', 
  '.js', '.json', '.map', '.pdf', '.xml', '.yml', '.zip', '.gz', '.tar', '.tgz', '.tar.gz',
  '.m4a', '.aac', '.mp3', '.wav', '.mpeg', '.mpg', '.ogg', '.ogv', '.mp4', '.m4v', '.webm'
]

console.log()
console.log(' Test suite')
console.log()

extensions.forEach(ext => {
  const file = 'file-' + Math.random(1) + ext
  const mime = get_mime_type(file)

  if (!types.includes(mime))
    throw new Error('Test fails for Mime Type: `' + mime + '`')

  console.log('    `%s`    => %s) test ✓', ext, mime)
})

console.log()
console.log('  TOTAL: ' + extensions.length + ' SUCCESS')
console.log()

console.log()
console.log('Test suite successful finished!')
console.log()
