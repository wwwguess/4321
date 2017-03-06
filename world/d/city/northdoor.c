// northdoor.c
#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
���Ǿ�ʦ�ı��ţ�������ǰ�����⵽����Ĺ�������Ե���
Щ�¾ɡ��������Ϸ������ɼ�����������д�ġ���ʦ���š�������
�֣���ǽ�����ż��Ÿ�ʾ(sign)���������ﷸ���������ıؾ�֮�أ�
�ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ�һ����ֱ����ʯ����
���ϱ��������졣�����ǽ��⣬����ġ����εġ���·�ģ����˴�
��ӿ�뾩ʦ���ϱ��ǳ����Լ�����������������
LONG
        );

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "out" :),
        ]) );

        set("exits", ([
                "out"            : __DIR__"nroad1",
                "south"          : __DIR__"street16" ]) );

        set("objects", ([
                __DIR__"npc/guard" : 3, ]) );  

        create_door("out", "����", "enter");
        setup();
}

string look_sign(object me)
{
       if( wizardp(me) )
                return "��ʾ��д����׽���������̩��\n";
        else
                return "��ʾ����Լд����������������ģ�����ɷֱ��ˡ�\n";
}

int valid_leave(object me,string dir)
{
        if ( dir=="out" && 
		( !(string) me->query("marks/��ʦ") 
		&& !(string) me->query("marks/����") ) ) {
		tell_object (me, "��ʦ�سǱ�˵����û�йٸ�ͨ��κ��˲��ܳ��뾩ʦ��\n");
                return notify_fail("���Ƿ����·����ʦ�سǱ���ס�ˡ�\n");
		}

	if (me->query("marks/����")) {
		::valid_leave(me,dir);
		me->set("marks/����", 0);
            me->set("have_token",0);
		return 1;
		}

        return ::valid_leave(me,dir);
}
