#!/bin/bash
#SBATCH --job-name=clap
#SBATCH --quotatype=auto
#SBATCH --partition=medai
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --gpus-per-task=3
#SBATCH --cpus-per-task=32
#SBATCH --mem-per-cpu=30G
#SBATCH --chdir=/mnt/petrelfs/sunluoyi/autoacd/logs/log/sbatch
#SBATCH --output=/mnt/petrelfs/sunluoyi/autoacd/logs/log/sbatch/%x-%j.out
#SBATCH --error=/mnt/petrelfs/sunluoyi/autoacd/logs/log/sbatch/%x-%j.error
#SBATCH -x SH-IDC1-10-140-0-[132,136,137,168-177,197,199,201,202,206,207,222-230,254],SH-IDC1-10-140-1-[3,9,10,12,18,24,30,33,35,44,57,58,60,61,88,148,151-160,162-165,167-177]
###SBATCH -w SH-IDC1-10-140-0-[...], SH-IDC1-10-140-1-[...]
###SBATCH -x SH-IDC1-10-140-0-[...], SH-IDC1-10-140-1-[...]


export NCCL_DEBUG=INFO
export NCCL_IBEXT_DISABLE=1
export NCCL_IB_DISABLE=1
export NCCL_SOCKET_IFNAME=eth2
echo "NODELIST="${SLURM_NODELIST}
master_addr=$(scontrol show hostnames "$SLURM_JOB_NODELIST" | head -n 1)
export MASTER_ADDR=$master_addr
MASTER_PORT=$((RANDOM % 101 + 20000))
# MASTER_PORT=36100
echo "MASTER_ADDR="$MASTER_ADDR



srun torchrun \
    --nnodes 1 \
    --nproc_per_node 3 \
    --rdzv_id 100 \
    --rdzv_backend c10d \
    --rdzv_endpoint=$MASTER_ADDR:$MASTER_PORT /mnt/petrelfs/sunluoyi/autoacd/code/CLAP_distribute/src/laion_clap/evaluate/eval_linear_probe-vggsound.py\
    --save-frequency 1 \
    --save-top-performance 3  \
    --save-most-recent    \
    --dataset-type="webdataset"   \
    --precision="fp32"   \
    --warmup 0     \
    --batch-size=256  \
    --lr=2e-5   \
    --wd=0.1    \
    --epochs=100    \
    --workers=8    \
    --use-bn-sync        \
    --amodel HTSAT-tiny    \
    --tmodel roberta     \
    --report-to "wandb"    \
    --datasetnames "vggsound"     \
    --datasetinfos "train"     \
    --seed 3407 \
    --logs /mnt/petrelfs/sunluoyi/autoacd/logs/ckpt-audioset \
    --pretrained /mnt/petrelfs/sunluoyi/autoacd/logs/pretrain_models/pretrain-ckpt-fusion/ \
    --lp-metrics "map"     \
    --lp-lr=2e-5    \
    --data-filling "pad"   \
    --gather-with-grad  \
    --top-k-checkpoint-select-metric "_mAP@10" \
    --data-truncating "fusion"     \
    --optimizer "adam"  \
    --openai-model-cache-dir  /mnt/petrelfs/sunluoyi/autoacd/logs/transformers_cache   \
    --wandb-notes "0305-scluster-test"