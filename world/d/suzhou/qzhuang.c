// Room: /d/suzhou/qzhuang.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit BANK;

string look_paizi();

void create()
{
	set("short", MAG"Ǯׯ"NOR);
	set("long", @LONG
	����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
ǽ�Ϲ���һ������(paizi)������д��Щ�֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"eroad1",
	]));

	set("item_desc" , ([
		"paizi" : (: look_paizi :),
	]));

	set("objects", ([
        	__DIR__"npc/shi2":1,
	]));

	setup();
}

string look_paizi()
{   string s1;
    return "��Ǯׯʵ���ۺ񣬻�ӭ��ҹ��١�\n" +
              "Ŀǰ�ṩ����\n"+
	      "�һ�Ǯ��(convert) \n"+
	      "����(check) \n" +
	      "��ȡǮ��(cun/qu)��\n";
}

