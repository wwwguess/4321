// Room: /d/hhu/center_2f.c
#include <room.h>

inherit ROOM;
string look_passwd ();
string look_bigcomputer();
string look_connect();
string look_computer();
string look_keyboard();
string look_work();

void create()
{
	set("short", "��������");
	set("long", @LONG
�����������Ӻ���ѧ������������ģ�
    ������������һ̨�����ӡ����ͼ����(bigcomputer),
    ���ܰ���ʮ��̨����(computer),ȴһ���˶�û�С�
    ��������͸¶��һ�����ص����գ�
LONG
	);
	set("item_desc", ([ /* sizeof() == 7 */
  "passwd" : (: look_passwd :),
  "connect" : (: look_connect :),
  "computer" : (: look_computer :),
  "bigcomputer" : (: look_bigcomputer :),
  "keyboard" : (: look_keyboard :),
  "yinhe" : (: look_bigcomputer :),
  "work" : (: look_work :),
]));
        set("no_fight",1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hhucenter",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
  add_action("do_press","press");
}

string look_passwd ()
{
  return "����û�У�������Կ���ɵ�ϣ�����ֻ��press��\n";
}

string look_computer()
{
  return "��Щ���������æµ�������ţ��͹Ŵ���ѩͤ���������ϵ(connect).\n�㲻����Ȼ����ԭ����ˣ�\n";
}
string look_connect()
{
  return "��Щ�������������(passwd),���޷���֪�����ڸ�ʲô��\n";
}
string look_bigcomputer()
{
  return "��̨�����ӡ����ͼ�������ڹ���(work)�У�\n���ļ���(keyboard)��һ��ҳ���û�У������Ѿ��þ�û�����û����ˡ�\nƾ�������ľ��飬����һ�������ܣ��ҵúú���һ��......\n";
}
string look_work()
{
  return "��Ļ��һ����ʾҲû�У����޷���֪���ڸ�ʲô��\n";
}
string look_keyboard()
{
  return "�������������֣���ֻ���ĸ��� A B C D\n��е��ǳ��ɻ󣬿����Ժ�Ҫ�ú�ѧϰ�����֪ʶ�ˡ�\n";
}
int do_press(string arg)
{
  int i;
  if (!arg||arg=="")
     return notify_fail("��Ҫ��ʲô��\n");
  if ((arg=="a")||(arg=="b")||(arg=="c")||(arg=="d"))
     return notify_fail("��ע���Сд��\n");
  if ((arg=="A")||(arg=="B")||(arg=="C")||(arg=="D"))
     {
      tell_room(__DIR__"center_2f",this_player()->name()+"����һ��"+arg+"��,����û��ʲô��Ӧ��\n");
      return notify_fail("���ˣ��ǲ��Ǹ�һ���Ӱ��ĸ����أ�\n");
     }
  if (arg=="passwd")
      return notify_fail("�������������룬����ʧ���ˣ�\n");
  if (arg!="DCAB")
      return notify_fail("��֪�������ﴫ����ѵ�����������Ұ���\n");
  tell_object(this_player(),"���������һ������֪��ʲô�������˽�ȥ��\n");
  tell_object(this_player(),"����ǰһ�ڣ�ʲô����������......\n");
  tell_object(this_player(),"����һ���������������������ʱ��ת�ƻ���������\n");
  tell_object(this_player(),"�ڰ��������س����˼����֣�\n");
  tell_object(this_player(),"          �Ӻ���ѧлл��Ĺ��٣���ӭ��������\n");
  tell_object(this_player(),"\nת�ۼ���ͳ�����ѩͤ�������ջ���㲻���е���ѧ�����ľ޴�\n");
  tell_room("/d/snow/inn",this_player()->name()+"��֪��������ð�˳��������������ǹŹ֣�\n");
  this_player()->move("/d/snow/inn");
  tell_room(__DIR__"center_2f",this_player()->name()+"��֪������ʲô������һ���Ӵ������ǰ��ʧ�ˡ�\n");
  return 1;
}
