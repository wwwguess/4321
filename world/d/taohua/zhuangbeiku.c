// Room: /d/new_taohua/zhuangbeiku.c

inherit ROOM;

void create()
{
	set("short", "װ����");
	set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�һ����������
����һ�����ӣ���δ���������ڲ�֪װ��ʲô��      
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  

            "north": __DIR__"yaopinfang",
 
          ]));

 set("item_desc", ([
                "����": "һ�����ӿ��Դ�(open)\n",
                "box":"һ�����ӿ��Դ�(open)\n",
           ]));  
          setup();
 }
 void init()
{
        add_action("do_open","open");
}
int do_open(string arg)
{ object zhi,me;
  me=this_player(); 
if ((random(10)>8) && !((int)me->query_temp("havejia")))
  {
  zhi=new(__DIR__"obj/ruanwei-jia"); 

  zhi->move(me);

  write( "\n�㷢����������һ�׼ף���������û�ˣ�˳�ֳ����Լ��Ŀڴ���\n");
  me->set_temp("havejia", 1);
  return 1;
  }
  write("������ʲô��û�С�\n");  
  me->set_temp("havejia", 1);
  return 1;
}
    





