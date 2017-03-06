#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ
��һ�����ٲ�����������������ٲ���ɽ��ֱ����£�������
�������������һ���ʯ����д�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"grassland1",
  "north" : __DIR__"lake2",
]));
        set("resource/water",1);
	set("outdoors", "taoguan");
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_swim", "swim");
}

int do_swim()
{
 object me;
 me = this_player();
 message_vision(HIY"$N���ŵ���������У���������...\n"NOR,me);
 if(random(me->query("kar"))<10) {
    tell_object(me,HIR"...���Ȼ�����ֽ�һ���һ��ˮ�Ѿ�Ǻ�˽�ȥ����æ�����˰���\n"NOR);
    me->receive_damage("kee",100);
    }else{
          tell_object(me,HIC"����ˮ�о���ĳ��Σ�������һ�з��ա�\n"NOR);
          me->add("gin",50);
         }
  return 1;
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 30,
                                "drunk_apply": 6,
                        ]) );
                        write("��Ӿ���װ������ˮ! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��");
        }
        return 1;
}
