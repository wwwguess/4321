// bank.c

inherit BANK;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
����һ�������������õ�Ǯׯ��Ǯׯ���ϰ嵹�Ƕ��������飬�Խ�
�ܻ��磬����Կ���Ǯׯ�������ⶼ��ɨ��ǬǬ������һ�����ݾ��ݵ�
���������ڹ�̨���棬��̨�Ϸ���һ������(sign)��������ͨ�����ǽ�
���Ĵ��š�
LONG
	);
	set("exits", ([ 
  "south" : "/d/city/street8",
]));

	set("objects", ([
 		"/d/city/npc/microsof" : 1 ]) );






	set("item_desc", ([
		"sign": @TEXT
�����ṩ�ķ����У�

convert     �һ�Ǯ�ң��Ե���Ŀ�����ź�����Ǯ�Ų�����

TEXT
	]) );
    set("no_fight", 1);
    set("no_magic", 1);
	setup();
}
