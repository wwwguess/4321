inherit NPC;
 
void create()
{
        set_name("���",  ({ "funlin","fun","lin" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
�����������С�龫��ͷ��������С����ͷ��
�����ڵ��ϣ������㿴�����������˸�����!
������һ���ǵ�Ƥ�Ż������ܷ�!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 2000);
        set_skill("unarmed", 20);
        set_skill("whip", 20);
        set_skill("dodge", 20);
        set_skill("move", 30);
        set_skill("stormdance", 20);
        map_skill("dodge","stormdance");
        set_skill("dodge", 30);
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 300);
        set("force_factor", 2);
        set_temp("apply/armor", 30);

         set("chat_chance", 7);
       set("chat_msg", ({
"��Ƥ�ķ��������������  *^G^* \n",
"����ߵ����룬һ������(Pose)����!��û�뵽������ʱ���д������衣\n",
"���˵���ò��ÿ���������һ��þ����ɵ�Ŷ! \n",
"��类������ƶ��������ϵĶ����仯��ǧ����һ��˵���������\n",
"���˵����÷�Ŷ! ���߿�! \n",
"���˵������ѧ����ȥ�����ǽ㣬����ı��Ҷࡣ��! \n",
"���˵����˹�! ��Ҫ���ҡ��߿���! \n",
"������졣�е������ķ���ͷȥ�������㣡\n"
       }) );
       create_family("����ׯ",5,"����");
        setup();
        carry_object(__DIR__"obj/whip")->wield();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt5")->wear();
}

int accept_object(object who, object ob)
{
     object me;
     string objname;

     me = this_player();
     objname = (string)ob->name();

        if ( objname != "������")  {
           command("smile");
            say ("��Ҫ�͸��Ұ�?! ��ô����˼!лл�㡣\n");
           command("blush");
             return 1;
            }
        if( !who->query_temp("moon/������") )  {

            tell_object(me, "��籺ܿ��ĵ����������Ѱ���!\n\n");
            tell_object(me, "�����м���лл��! ��С�����������˵��\n");
            tell_object(me, "�� ׯ��ǰ��ĳ������һ��������Ŷ!��\n");
            tell_object(me, "��������ҿ�! (search bracelet) \n");
            who->set_temp("moon/�����", 1);
            who->set_temp("moon/������", 1);
         } else {
             say ("лл!���Ѿ�������������ѽ!ȥ��ѽ! \n");
             return 1;
          }
          return 1;
}
