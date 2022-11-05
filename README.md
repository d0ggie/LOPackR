LOPACKR
=======

## Summary

`LOPackR` extracts stored payloads from LibreOffice backup `.pack` files.  A single backup file contains up to ten individual payloads.  Typically these are not the same, but previous versions of the file.

The backup files are identified by `.pack` suffix or `PACK` (0x48434150) magic number.  The files are often stored in user profile directory.

The majority of time the individual backup payload is compressed, but uncompressed payloads are supported as well.  A simple CRC-32 checksum is used to guarantee validity of the uncompressed payload.

No metadata of any kind, e.g. filenames or timetamps, is stored onto backup file (excluding what the actual payload might contain).

### `.pack` File Format

The format is documented in `LOPackREntry.hxx`.

## Usage

```
LOPackR <file>...
```

There are no command line options.  Simply pass in the input file(s).  A corresponding output file will be created using `.full__<index>` suffix.  If the file already exists it is overwritten without a prompt.  This tool is for cowboys!

### Exit value

The tool returns a non-zero exit value in case of emergency, zero otherwise.  This is the industry standard.

## Compiling

Install GCC that supports `gnu++20` and `zlib-devel` (or similar development version containing headers) zlib compression library.  Then, make the program using GNU make `make` and you are good to go.
