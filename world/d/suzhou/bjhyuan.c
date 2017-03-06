//ROOM:/d/suzhou/bjhyuan.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ROOM;

string* objects = ({
        "flower",
        "stone",
});
 
void create()
{
	int i = random(sizeof(objects));

	set("short", MAG"��԰"NOR);
	set("long", @LONG
�����ھֺ�԰�������и��ֻ��ݣ���ɽ��ʮ������ϲ����ͻȻ�㿴��һ��õ�壬Ҫ
�ǰ�����������ˣ��Ǹö�ð���	
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"south" : __DIR__"bjdting", 
		"northeast" : __DIR__"dzju",
		"east" : __DIR__"chufan",
	]));

        set("objects", ([
	__DIR__"npc/obj/"+objects[i] : 1]));
                                    

	setup();
}

