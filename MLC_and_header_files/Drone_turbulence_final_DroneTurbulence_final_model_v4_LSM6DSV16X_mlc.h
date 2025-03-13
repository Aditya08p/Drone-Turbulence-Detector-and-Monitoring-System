
/**
 * ST AIoT Craft info
 * Project name: Drone_turbulence_final
 * Project id: 5ee7cc97-8f9b-4456-a250-95fd5f80fe33
 * Model name: DroneTurbulence_final_model_v4
 * Model id: 7748c610-4f12-406d-a6ca-25795e3db8f3
 */

                           
/**
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef LSM6DSV16X_MLC_H
#define LSM6DSV16X_MLC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define LSM6DSV16X_MLC_SENSORS_NUM 1

#ifndef MEMS_CONF_SHARED_TYPES
#define MEMS_CONF_SHARED_TYPES

#define MEMS_CONF_ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

/*
 * MEMS_CONF_SHARED_TYPES format supports the following operations:
 * - MEMS_CONF_OP_TYPE_TYPE_READ: read the register at the location specified
 *   by the "address" field ("data" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_WRITE: write the value specified by the "data"
 *   field at the location specified by the "address" field
 * - MEMS_CONF_OP_TYPE_TYPE_DELAY: wait the number of milliseconds specified by
 *   the "data" field ("address" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_SET: poll the register at the location
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are set to 1
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_RESET: poll the register at the location 
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are reset to 0
 */

struct mems_conf_application {
	char *name;
	char *version;
};

struct mems_conf_name_list {
	const char *const *list;
	uint16_t len;
};

enum {
	MEMS_CONF_OP_TYPE_READ = 1,
	MEMS_CONF_OP_TYPE_WRITE = 2,
	MEMS_CONF_OP_TYPE_DELAY = 3,
	MEMS_CONF_OP_TYPE_POLL_SET = 4,
	MEMS_CONF_OP_TYPE_POLL_RESET = 5
};

struct mems_conf_op {
	uint8_t type;
	uint8_t address;
	uint8_t data;
};

struct mems_conf_op_list {
	const struct mems_conf_op *list;
	uint32_t len;
};

struct mems_conf_result {
	uint8_t code;
	char *label;
};

enum {
	MEMS_CONF_OUTPUT_CORE_HW = 1,
	MEMS_CONF_OUTPUT_CORE_EMB = 2,
	MEMS_CONF_OUTPUT_CORE_FSM = 3,
	MEMS_CONF_OUTPUT_CORE_MLC = 4,
	MEMS_CONF_OUTPUT_CORE_ISPU = 5
};

enum {
	MEMS_CONF_OUTPUT_TYPE_UINT8_T = 1,
	MEMS_CONF_OUTPUT_TYPE_INT8_T = 2,
	MEMS_CONF_OUTPUT_TYPE_CHAR = 3,
	MEMS_CONF_OUTPUT_TYPE_UINT16_T = 4,
	MEMS_CONF_OUTPUT_TYPE_INT16_T = 5,
	MEMS_CONF_OUTPUT_TYPE_UINT32_T = 6,
	MEMS_CONF_OUTPUT_TYPE_INT32_T = 7,
	MEMS_CONF_OUTPUT_TYPE_UINT64_T = 8,
	MEMS_CONF_OUTPUT_TYPE_INT64_T = 9,
	MEMS_CONF_OUTPUT_TYPE_HALF = 10,
	MEMS_CONF_OUTPUT_TYPE_FLOAT = 11,
	MEMS_CONF_OUTPUT_TYPE_DOUBLE = 12
};

struct mems_conf_output {
	char *name;
	uint8_t core;
	uint8_t type;
	uint16_t len;
	uint8_t reg_addr;
	char *reg_name;
	uint8_t num_results;
	const struct mems_conf_result *results;
};

struct mems_conf_output_list {
	const struct mems_conf_output *list;
	uint16_t len;
};

struct mems_conf_fifo_encoding {
	uint8_t tag;
	uint16_t id;
	char *label;
};

struct mems_conf_fifo_encoding_list {
	const struct mems_conf_fifo_encoding *list;
	uint16_t len;
};

#endif /* MEMS_CONF_SHARED_TYPES */

static const char *const lsm6dsv16x_mlc_format_version = "2.0";

static const struct mems_conf_application lsm6dsv16x_mlc_application = {
	.name = "MLC Tool",
	.version = "2.0.7"
};

static const char *const lsm6dsv16x_mlc_description = "Generated sensor configuration for MLC core";

static const char *const lsm6dsv16x_mlc_date = "2025-03-13 12:39:08";

/* Names */

static const char *const lsm6dsv16x_mlc_names_0[] = {
	"LSM6DSV16X"
};

static const struct mems_conf_name_list lsm6dsv16x_mlc_name_lists[LSM6DSV16X_MLC_SENSORS_NUM] = {
	{ .list = lsm6dsv16x_mlc_names_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(lsm6dsv16x_mlc_names_0) }
};

/* Outputs */

static const struct mems_conf_result lsm6dsv16x_mlc_results_0_0[] = {
	{ .code = 0x00, .label = "no_power" },
	{ .code = 0x01, .label = "roll_left" },
	{ .code = 0x04, .label = "armed" },
	{ .code = 0x05, .label = "roll_right" },
	{ .code = 0x08, .label = "pitch_forward" },
	{ .code = 0x09, .label = "motion_stable" },
	{ .code = 0x0C, .label = "pitch_backward" },
	{ .code = 0x0D, .label = "motion_turbulence" }
};

static const struct mems_conf_output lsm6dsv16x_mlc_outputs_0[] = {
	{
		.name = "Categorical output",
		.core = MEMS_CONF_OUTPUT_CORE_MLC,
		.type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
		.len = 1,
		.reg_addr = 0x70,
		.reg_name = "MLC1_SRC",
		.num_results = (uint8_t)MEMS_CONF_ARRAY_LEN(lsm6dsv16x_mlc_results_0_0),
		.results = lsm6dsv16x_mlc_results_0_0
	}
};

static const struct mems_conf_output_list lsm6dsv16x_mlc_output_lists[LSM6DSV16X_MLC_SENSORS_NUM] = {
	{ .list = lsm6dsv16x_mlc_outputs_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(lsm6dsv16x_mlc_outputs_0) }
};

/* FIFO encodings */

static const struct mems_conf_fifo_encoding lsm6dsv16x_mlc_fifo_encodings_0[] = {
	{ .tag = 0x1C, .id = 0x03C4, .label = "F1_MINIMUM_ACC_Y" },
	{ .tag = 0x1C, .id = 0x03C6, .label = "F2_MEAN_ACC_X" },
	{ .tag = 0x1C, .id = 0x03C8, .label = "F3_MEAN_ACC_Y" },
	{ .tag = 0x1C, .id = 0x03CA, .label = "F4_ENERGY_ACC_Y" },
	{ .tag = 0x1C, .id = 0x03CC, .label = "F5_MAXIMUM_ACC_X" },
	{ .tag = 0x1C, .id = 0x03CE, .label = "F6_MINIMUM_ACC_X" },
	{ .tag = 0x1C, .id = 0x03D0, .label = "F7_ABS_MEAN_GYR_V" },
	{ .tag = 0x1C, .id = 0x03D2, .label = "F8_VARIANCE_ACC_Y" },
	{ .tag = 0x1C, .id = 0x03D4, .label = "F9_PEAK_TO_PEAK_GYR_Y" },
	{ .tag = 0x1C, .id = 0x03D6, .label = "F10_ENERGY_ACC_X" },
	{ .tag = 0x1C, .id = 0x03D8, .label = "F11_MAXIMUM_ACC_Z" },
	{ .tag = 0x1C, .id = 0x03DA, .label = "F12_MINIMUM_GYR_Z" },
	{ .tag = 0x1C, .id = 0x03DC, .label = "F13_MAXIMUM_GYR_Y" },
	{ .tag = 0x1C, .id = 0x03DE, .label = "F14_MAXIMUM_ACC_Y" },
	{ .tag = 0x1C, .id = 0x03E0, .label = "F15_PEAK_TO_PEAK_ACC_X" }
};

static const struct mems_conf_fifo_encoding_list lsm6dsv16x_mlc_fifo_encoding_lists[LSM6DSV16X_MLC_SENSORS_NUM] = {
	{ .list = lsm6dsv16x_mlc_fifo_encodings_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(lsm6dsv16x_mlc_fifo_encodings_0) }
};

/* Configurations */

static const struct mems_conf_op lsm6dsv16x_mlc_conf_0[] = {
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x10, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x11, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xE8 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xF1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x21 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xEA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xC4 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x14 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xF2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFF },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xFA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x5C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xEE },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x5C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x10 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x10 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xA4 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x10 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x20 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x11 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xE2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x31 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xEE },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x56 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB3 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x09 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0D },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB4 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x28 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xC2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xA7 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x2E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x05 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x86 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x2D },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x4D },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xC2 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x95 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x9E },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x41 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xD9 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB3 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x29 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x08 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x82 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x90 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xAA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x90 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xAB },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xDC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xB1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xD9 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xEB },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xDA },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x9D },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xD9 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFE },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x9F },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x81 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x23 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xA0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x90 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xAC },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x45 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x68 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xAF },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xC1 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE0 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x10 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x5E, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x80 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0D, .data = 0x01 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x60, .data = 0x45 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x45, .data = 0x02 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x01, .data = 0x00 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x10, .data = 0x07 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x11, .data = 0x07 },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x15, .data = 0x0C },
	{ .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x03 }
};

static const struct mems_conf_op_list lsm6dsv16x_mlc_confs[LSM6DSV16X_MLC_SENSORS_NUM] = {
	{ .list = lsm6dsv16x_mlc_conf_0, .len = (uint32_t)MEMS_CONF_ARRAY_LEN(lsm6dsv16x_mlc_conf_0) }
};

#ifdef __cplusplus
}
#endif

#endif

