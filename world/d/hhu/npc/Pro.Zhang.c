
inherit NPC;

void follow_player();

void create()
{
	set_name("�Ž���",({"pro_zhang","teacher"}));
	set("title", "����");
	set("gender", "����" );
	set("age", 42);
        set("combat_exp",1200);
        set("int",10);
        set("long",@LONG
���Ǹ���ѧ��ŵĽ��ڣ�ͬѧ�Ƕ��ܾ�������
LONG
);
      set("env/wimpy",50);
      set("chat_chance",10);
      set("chat_msg",({
         "�Ž����ʣ�����ʲô����Ҫ����ң�\n",
         (: random_move :),
         "�Ž���˵����ʲô�����Ժ���˵�ɣ���Ҫȥ�Ͽ��ˡ�\n",
        }));
      set("attitude","peaceful");
      set_skill("literate",150);
      set_skill("sword",80);
      setup();
      carry_object(__DIR__"obj/pen")->wield();
}
