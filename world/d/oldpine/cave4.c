// Room: /d/oldpine/cave1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�������Ѿ�����ɽ�������, ����˷�����Щ�������Сʯ��,
��ֱ��֪������������, Ҫ���Ǳ��滹��һ�����, �㶼Ҫ���׾����ˡ�
LONG
	);

	setup();
}

void reset()
{
        ::reset();
        
	set("exits", ([ /* sizeof() == 4 */
        	"south" : __DIR__"cave" + (random(4)+1),
          	"north" : __DIR__"cave" + (random(4)+1),
          	"west" : __DIR__"cave5",
          	"east" : __DIR__"cave" + (random(4)+1),
        ]));
}

