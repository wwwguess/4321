
inherit NPC;

string answer_2();
string answer_3();

void follow_player();

void create()
{
        set_name("������",({"pro_wang","teacher"}));
	set("title", "����");
	set("gender", "����" );
	set("age", 47);
        set("combat_exp",1800);
        set("int",10);
        set("long",@LONG
���Ǹ���ѧ��ŵĽ��ڣ�ͬѧ�Ƕ��ܾ�������
LONG
);
      set("chat_chance",10);
      set("chat_msg",({
         "�������ʣ�����ʲô����Ҫ����ң�\n",
         "������˵����ʲô�����Ժ���˵�ɣ���Ҫȥ�Ͽ��ˡ�\n",
        }));
      set("attitude","friendly");
      set("inquiry", ([
          "1+1" : (: answer_2 :),
          "1+2" : (: answer_3 :),
      ]) );
      set_skill("literate",150);
      set_skill("throwing",80);
      setup();
      carry_object(__DIR__"obj/chalk")->wield();
}

string answer_2()
{
      return "��ô�򵥵�����Ҳ����,1+1=2��!�汿! \n";
}

string answer_3()
{
      return "�������Ƚ���,��Ҫ�о��о�,�������ٸ�����!\n";
}
