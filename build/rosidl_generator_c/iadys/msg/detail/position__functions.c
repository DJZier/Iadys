// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from iadys:msg/Position.idl
// generated code does not contain a copyright notice
#include "iadys/msg/detail/position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
iadys__msg__Position__init(iadys__msg__Position * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // teta
  return true;
}

void
iadys__msg__Position__fini(iadys__msg__Position * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // teta
}

iadys__msg__Position *
iadys__msg__Position__create()
{
  iadys__msg__Position * msg = (iadys__msg__Position *)malloc(sizeof(iadys__msg__Position));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(iadys__msg__Position));
  bool success = iadys__msg__Position__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
iadys__msg__Position__destroy(iadys__msg__Position * msg)
{
  if (msg) {
    iadys__msg__Position__fini(msg);
  }
  free(msg);
}


bool
iadys__msg__Position__Sequence__init(iadys__msg__Position__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  iadys__msg__Position * data = NULL;
  if (size) {
    data = (iadys__msg__Position *)calloc(size, sizeof(iadys__msg__Position));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = iadys__msg__Position__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        iadys__msg__Position__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
iadys__msg__Position__Sequence__fini(iadys__msg__Position__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      iadys__msg__Position__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

iadys__msg__Position__Sequence *
iadys__msg__Position__Sequence__create(size_t size)
{
  iadys__msg__Position__Sequence * array = (iadys__msg__Position__Sequence *)malloc(sizeof(iadys__msg__Position__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = iadys__msg__Position__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
iadys__msg__Position__Sequence__destroy(iadys__msg__Position__Sequence * array)
{
  if (array) {
    iadys__msg__Position__Sequence__fini(array);
  }
  free(array);
}
