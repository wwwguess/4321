//si men

#include <ansi.h>

inherit ROOM;

void create()
{
        string *midao=({
                                 __DIR__"midao0",
                                 __DIR__"midao1",
                                 __DIR__"midao2",
                                 __DIR__"midao3",
                                 __DIR__"midao4",
                                 __DIR__"midao5",
                                 __DIR__"midao6",
                                 __DIR__"midao7",
                        });

        int i;

        i=random(257);
        
        set("short", "�ص�");
        set("long",@LONG
    ���������ģ�ǽ���Ϲ���һյ�͵ƣ����Ż�Ƶ�΢�⣬��Χ�а˸�����
�ܸе�����ɱ�����д������㲻�ɵô��˸���ս��
LONG
                );
        set("exits", ([    
              "east" : midao[(i+0)%8],
         "southeast" : midao[(i+1)%8],
             "south" : midao[(i+2)%8],
         "southwest" : midao[(i+3)%8],
              "west" : midao[(i+4)%8],
         "northwest" : midao[(i+5)%8],
             "north" : midao[(i+6)%8],
         "northeast" : midao[(i+7)%8],
	]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        int j;

        create();

        j=me->query_temp("bagua/si");
        j++;
        me->set_temp("bagua/si",j);

        if (j>20)
        {
		message_vision(HIY "$NͻȻ��������! һ���ʯ��$Nͷ�����£�$N���ҳ�һ�����ࡣ\n" NOR,me);
		me->die();
		return 0;
        }

        return ::valid_leave(me,dir);
}
