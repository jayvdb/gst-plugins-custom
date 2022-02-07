/* GStreamer
 * Copyright (C) <2019> Seungha Yang <seungha.yang@navercorp.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_CUDA_SCALE_H__
#define __GST_CUDA_SCALE_H__

#include <gst/gst.h>

#include <gst/cuda/nvcodec/cuda-converter.h>
#include <gst/cuda/nvcodec/gstcudabasefilter.h>

G_BEGIN_DECLS

#define GST_TYPE_CUDA_SCALE             (gst_cuda_scale_get_type())
#define GST_CUDA_SCALE(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_CUDA_SCALE,GstCudaScale))
#define GST_CUDA_SCALE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_CUDA_SCALE,GstCudaScaleClass))
#define GST_CUDA_SCALE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), GST_TYPE_CUDA_SCALE,GstCudaScaleClass))
#define GST_IS_CUDA_SCALE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_CUDA_SCALE))
#define GST_IS_CUDA_SCALE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_CUDA_SCALE))

typedef struct _GstCudaScale GstCudaScale;
typedef struct _GstCudaScaleClass GstCudaScaleClass;

struct _GstCudaScale
{
  GstCudaBaseFilter parent;

  GstCudaConverter *converter;

  CUdeviceptr in_fallback;
  CUdeviceptr out_fallback;
};

struct _GstCudaScaleClass
{
  GstCudaBaseFilterClass parent_class;
};

GType gst_cuda_scale_get_type (void);

G_END_DECLS

#endif /* __GST_CUDA_SCALE_H__ */
