// Room: /d/taohua/qyfroom.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������һ�����ʦ�������ľ��������ڳ���
���ӣ�ֻ��һЩ����ر�֮�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "south" : __DIR__"yonglu7",
  
]));
        set("objects",([
                CLASS_D("taohua") + "/qulingf.c" : 1,
            ]));	

	setup();
	
}
