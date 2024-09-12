# A Large-scale Dataset for Audio-Language Representation Learning

Luoyi Sun, Xuenan Xu, Mengyue Wu, Weidi Xie

[[project page]](https://auto-acd.github.io/)
[[Arxiv]](https://arxiv.org/abs/2309.11500)
[[Dataset]](https://huggingface.co/datasets/Loie/Auto-ACD)

## Environments

```bash
conda create env -n acd python=3.10
conda activate acd
pip install torch==1.11.0+cu113 torchvision==0.12.0+cu113 torchaudio==0.11.0+cu113 -f https://download.pytorch.org/whl/torch_stable.html
pip install -r requirements.txt
wandb login ***
```


## Training
Modify the paths in [`data.py`](./laion_clap/training/data.py).

The training command is:
```
cd ./laion_clap/evaluate

CUDA_VISIBLE_DEVICES=0  python eval_linear_probe-acd.py   
--save-frequency 5  
--save-top-performance 3  
--save-most-recent    
--dataset-type="webdataset"   
--precision="fp32"   
--warmup 1000    
--batch-size=256    
--lr=1e-4    
--wd=0.1    
--epochs=15  
--workers=8   
--use-bn-sync        
--amodel HTSAT-tiny    
--tmodel roberta     
--report-to "wandb"     
--wandb-notes "acd"     
--datasetnames "dataset"     
--datasetinfos "train"     
--seed 3407        
--logs ./logs/ckpt     
--gather-with-grad     
--lp-loss="bce"     
--lp-metrics="map"     
--lp-lr=1e-4     
--openai-model-cache-dir ./transformers_cache     
--pretrained="./pretrain-ckpt"     
--data-filling "repeatpad"    
--data-truncating "rand_trunc"     
--optimizer "adam"
```
<!-- 
## Inference

The inference command is:
```
python main.py --gpu 0 --config_file configs/htm.yaml --run_name eval
``` -->

**[Optional] Evaluating Our Pre-trained Model**

We also provide pre-trained models. The model with all training logs can be downloaded from [HuggingFace](https://huggingface.co/Loie/AutoACD). 


## Citation
If you are using our code, please consider citing our paper.
```bibtex
@inproceedings{sun2024auto,
  title={Auto-ACD: A Large-scale Dataset for Audio-Language Representation Learning},
  author={Sun, Luoyi and Xu, Xuenan and Wu, Mengyue and Xie, Weidi},
  booktitle={ACM Multimedia 2024}
}
```


## Contact
If you have any question, please feel free to contact loiesun411@gmail.com.


## Aknowledgement
This repo benefits from [CLAP](https://github.com/LAION-AI/CLAP). Thanks for their wonderful works.
