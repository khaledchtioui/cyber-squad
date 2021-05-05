//////////////////////////////////////////
//list.c
//////////////////////////////////////////
//Implémentation de la liste chainée pour 
//Snake
//////////////////////////////////////////
//Crée le : 10-10-2015 
//Par : momole02
//////////////////////////////////////////

#include "stdinc.h"
#include <stdlib.h>
#include <memory.h>
#include "snake.h"
#include "defs.h"

void SList_Init(SList_t * list)
{
	memset(list , 0 , sizeof(SList_t));
}

void SList_Push(SList_t * list )
{
	SNode_t * node = malloc(sizeof(SNode_t)) ;
	if(!node)
		return ;	
		
	node->next = NULL;
	
	if(!list->first){	//Liste vide
		node->x = 0 ; 
		node->y = 0 ; 
		node->vx = 1;
		node->vy = 0 ; 
		list->first = node ; 
		list->last = list->first;
		
	}else{	//Contient au moins 1 élément
		node->x = list->last->x - list->last->vx;
		node->y = list->last->y - list->last->vy;
		node->vx = list->last->vx ;
		node->vy = list->last->vy ;
		list->last->next = node ; 	//Ajouter au dernier 
		list->last = list->last->next; 	//Marquer ce noeud comme dernier
	}	
}

int SList_IsOnSnake(SList_t * list , int x , int y , int with_first)
{
	SNode_t * node = NULL;
	
	if(with_first)
		node = list->first ; 
	else{
		if(list->first != NULL)
			node = list->first->next ; 
	}
	
	while(node != NULL){
		if(x==node->x && y == node->y)		
			return 1; 
		node = node->next;
	}
	return 0 ;
}

void SList_DisplaySnake(SList_t * list , u8 * p)
{
	SNode_t * node = list->first ; 
	
	while(node != NULL){
		p[(node->y*NBLOCKS_W)+node->x] = IT_SNAKE_PART;
		node = node->next;
	}
}

void SList_SnakeMove(SList_t * list)
{
	int vx , vy ; 
	int tvx , tvy ; 
	
	SNode_t * node ; 
	//Liste vide
	if(!list->first)
		return ; 
	
	
	list->first->x += list->first->vx ; 
	list->first->y += list->first->vy ; 
	
	vx = list->first->vx ; 
	vy = list->first->vy ; 
	
	node = list->first->next ; 
	
	while(node != NULL){
		node->x += node->vx ; 
		node->y += node->vy ; 
		
		//Prend le vecteur du parent
		tvx = node->vx;
		tvy = node->vy ; 
		node->vx = vx ; 
		node->vy = vy ; 
		
		//Donne son vecteur au suivant
		vx = tvx; 
		vy = tvy; 

		node = node->next ; 
	}
}

void SList_SetVector(SList_t * list , int vx , int vy)
{
	if(list->first->next != NULL){	//Eviter les retournements brusques
		if(list->first->next->vx == -vx && list->first->next->vy == -vy)
				return ; 
	}
	
	list->first->vx = vx ; 
	list->first->vy = vy ; 
}

void freenode(SNode_t * node)
{
	if(node != NULL){
		if(node->next != NULL){
			freenode(node->next);
			node->next = NULL;
		}
		free(node);
	}
	
	
}

void SList_Free(SList_t * list)
{
	freenode(list->first);
	list->first = NULL;
}

