/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ libgnu / libgnu /
  tb
  s/ $/ libgnu /
  :b
  s/^/# Packages using this file:/
}
