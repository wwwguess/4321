// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit BANK;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
	����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ������̨�Ϸ���һ������(sign)��
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));

        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�

TEXT
        ]) );


//	set("objects", ([
//      __DIR__"npc/shi":1,
//	]));

	setup();
//	replace_program(ROOM);
}
