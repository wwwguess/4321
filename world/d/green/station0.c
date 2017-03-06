// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
�����ǲ�ʯ���ڴ�ڵĹ���վ��һ��СС��ľ�����ڶ��ߣ��Ա���һ
����ɽ��б�¡�·����һ�ھ����յ���ͣ����������ʯ�ϵĳ���������һ
��������ʯ���·��һ·��ɽ�������ȥ��
LONG
	);
    set("exits", ([
    "northeast" : __DIR__"station1",
    "west" : __DIR__"path5",
]));
	set("objects", ([
    __DIR__"npc/worker2" : 3,
	]) );
    set("resource/water",1);
    set("outdoors", "snow");
	setup();
	replace_program(ROOM);
}

void init()
{
        add_action("do_fillwater", "fillwater");
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
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��Ӿ���װ������ˮ! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�������....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��");
        }
        return 1;
}

