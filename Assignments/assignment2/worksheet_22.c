int linkedListContains (struct linkedList *lst, TYPE e) {
	assert(lst != 0);
	struct dLink * itr = lst->frontSentinal->next;
	
	while(itr != 0)
	{
		if(EQ(itr->value,e)) { return 1; }
		itr = itr->next;
	}
	return 0;
}


void linkedListRemove (struct linkedList *lst, TYPE e) {
	assert(lst != 0);
	if(linkedListContains(lst,e))
	{
		struct dlink * itr = lst->frontSentinal->next;
		while(itr != 0)
		{
			if(EQ(itr->value,e))
			{
				itr->prev->next = itr->next;
				itr->next->prev = itr->prev;
				free(itr);
				itr = 0;
			}
			itr = itr->next;
		}
	}
}

