
inherit ROOM;

void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
·������һ��ʯ��������д��������׭�֣���ɽ��        
��ɽ�ȿ�ȥ��һ������������С·������ڣ�����һΣ��ǰͻȻ�жϡ�
LONG
        );
        set("exits", ([ 
  "northup" : "/u/taoguan/road1",
  "eastdown" : __DIR__"troad1",
]));
	set("outdoors","tieflag"); 	
        
        setup();
}

