inherit ROOM;

void create()
{
	set("short","�շ���");
	set("long",@LONG
������ ES2 �ġ��뵺����ѵ��, ����㱻�͵�����, ��ʾ:
��Υ������Ϸ����, ��úõķ�ʡһ�����������Ϊ, ����
���Ļ�ֻҪ���߳��� 15 ���Ӽ��� :-) 
LONG
	);
	setup();
}

void init()
{
	if (!wizardp(this_player())) 
	add_action("block_cmd","",1);
}

int block_cmd()
{
	if((string)query_verb() == "look") return 0;
	if((string)query_verb() == "help") return 0;
	return 1;
}
