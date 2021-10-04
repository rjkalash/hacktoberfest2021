
function getFlags () {
  const query = qs.parse(window.location.search.slice(1))
  Object.entries(query).forEach(([k, v]) => {
    delete query[k]
    if (k.indexOf('flag-') !== 0) return
    query[k.replace('flag-', '')] = v
  })
  return util.parseBooleanObject(query)
}
