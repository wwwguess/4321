 // houhuayuan1.c
// by yuer
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ǹ������ĺ�԰�������˻��ݡ�����Сͯ���ڽ���
������һ�����ŵ�СԺ��
LONG
        );
        set("exits", ([
		"north" : __DIR__"yueliangmen",
		"south" : __DIR__"zoulang0",
		 "west" : __DIR__"chitang",
		 "east" : __DIR__"jiashan",
	]));
        
        set("no_clean_up", 0);
        set("outdoors", "mingjiao" );
        setup();
       
}


