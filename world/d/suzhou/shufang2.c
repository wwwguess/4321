//ROOM:/d/suzhou/shufang2.c
//changed by dwolf
//97.11.4

inherit ROOM;

void create()
{
	set("short", "�鷿");
        set("long", 
"   ����һ�����ķ��䣬�ұ��и���������߿�ǽ��һ����ܡ�\n"
"����Ϸ���һϵ�е��飬���߽�һ�����ۣ��ǽ�ӹ������\n"
"\n"
"         �������˲���\n\n"
"��������һ�����Ӻ͵��ӣ��������������Ϣһ�¡�������(read)\n"
"������Ŀǰֻ��\n"
"12  14  16  18  2   21  27  29  41  43  45  47  49 \n"
"���½ڣ���Ķ����˽�ȥ��\n"
 );
      set("exits", ([
                "west" : __DIR__"ymhting",
      ]));
	setup();
}

void init()
{
 add_action("do_read", "read");

}

int do_read(string arg)
{
 object me;
 me = this_player();
 if( !arg ) {
      me->start_more(read_file("/d/library/tian/0") );
       return 1;
 }
 if( file_size("/d/library/tian/"+arg)>0 ){
      me->start_more(read_file("/d/library/tian/"+arg) );
      return 1;
 } else {
  return notify_fail("û���Ȿ��\n");
 }

}
