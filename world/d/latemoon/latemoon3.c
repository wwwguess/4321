
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short","����");
	set("long", @LONG
����������ׯ�Ӵ����͵İ��������а���һ���������������
һ������������������������������п�����������̫ʦ
��������������һ���µĲ��������ʢ�õ��ϵ����衣
LONG
	);
    set("resource/water", 1);
	set("exits", ([ /* sizeof() == 2 */
    "south" :__DIR__"latemoon1",
]));

    set("objects", ([
         __DIR__"npc/yumay" : 1  ]) );
	setup();
}
int valid_leave(object me, string dir)
{
        string item;
        object obj;

        item = "tea cup";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "�����������뿪!\n" NOR );
        }  else  {
        if ( me->query_temp("latemoon/��") ) {
                tell_object(me, HIC "�㽫�ɱ����ظ���÷��\n" NOR);
                me->set_temp("latemoon/��", 0);
        destruct(obj);
           }
        }
        return 1;
}
