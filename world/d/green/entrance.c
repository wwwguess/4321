#include <room.h>

inherit ROOM;

void create()
{
        set("short","ɽ·��ͷ");
        set("long",@LONG
���ߵ���ɽ·�ľ�ͷ���������涼��ʯ�ڣ�����ʯ������һ�����ڣ���������
��������֮���������Ϸ��ƺ�����һ��ͼ(painting)��������һ�ȴ�ʯ�ţ�
����̦���߰ߣ���Ȼ�Ѿ��ܾ�û�˴򿪹��ˡ�
LONG
);
        set("exits",([ /* sizeof() == 3 */
                "north": __DIR__"outdoor",
                "east" : __DIR__"eight0",
                "south": __DIR__"mpath2",
        ])
	);
        create_door("north","��ʯ��","south", DOOR_CLOSED);
        set("item_desc",([ 
        "painting":"����һ��������ͼ,ͼ������һ��ģ����С�֣����Թ���\n"
        ]) 
        );

        set("no_clean_up",0);
        setup();
}

int valid_leave(object me,string dir)
{
        if ( dir == "east" && me->query("combat_exp") < 100000 ) 
                return notify_fail("����ʯ����ȥ����Ȼһ����ӿ��������ܲ�ס��ֻ�����˻���\n");
        if ( dir == "east" ) {
		tell_room(environment(me),(string)me->query("name")+
        "��ʯ����ȥ�����ű���ʧ������֮��......\n",
        ({this_object(), me}));
	return 1 ;
	}
         else   return ::valid_leave(me,dir);
}

