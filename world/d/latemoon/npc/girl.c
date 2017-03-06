inherit NPC;
 string show_dance();
string show_dragon();
 
void create()
{
        set_name("����", ({ "zauyi", "joe" }) );
        set("title", "����ׯ����������");
        set("gender", "Ů��" );
        set("age",17);
        set("long", @TEXT
���������ǳ��ɰ�������������£�����������
��һ��ӡ����������赸һ�����Ĳ���������һ��һ��
��һ��˵�������������ţ�
TEXT
);
       set("class", "dancer");
        set("combat_exp", 4000);
        set("kee",270);
        set("san",100);
        set_skill("unarmed",20);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("blade",10);
         set_skill("spring-blade",7);
        map_skill("blade", "spring-blade");
        set_skill("force",50);
        set("force",450);
       set("max_force",450);
        set("force_factor", 2);
        set_temp("apply/armor", 30);
        set("inquiry", ([
         "ͼ" : "����һ�ŷǳ�������������ͼ����Ҳ���о��С�\n",
         "�׺�����" : "�� ...Ϊ�����������ƺ���÷�֪����\n",
         "�з�����" : "�� ...Ϊ����������(dancing yu-fong)�������� \n",
         "��������" : "����Ӱʽ�貽��������ص㶼����Ҫ��\n",
         "���" : "����������������һЩ�Դ����貽��\n",
         "��" : "�׺�������һ����������ͼ������һЩ����貽��\n",
            "��������" : (: this_object(), "show_dance" :),
            "��" : (: this_object(), "show_dragon" :)
        ]));
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"������������貽���ڷ�����������!�㿴������\n",
"����̧ͷ�����Ƿ�ͼ����������˼... \n"
        }) );
      carry_object(__DIR__"obj/yu_blade")->wield();
      carry_object(__DIR__"obj/flower_boot")->wear();
}

string show_dance()
{
        object me;
        string str;
        str = (string)this_object()->query("name");
        me = this_player();
        tell_object(me, str+"����ֵ������㣬˵��:��!���������Ȥѽ! \n");
        tell_object(me,"ֻ������������ȥ��һ�ֺ����صı��飬����졣\n");
        tell_object(me,"����һ��˵���ð�!͵͵����˵������Բ鿴ǽ��"
     +"��ͼ��(dragon-dance) \n");
        return "....\n";
}
string show_dragon()
{
      object me;
      string str;
      str = (string)this_object()->query("name");
      me = this_player();
      tell_object(me, str+"�ܸ��˵Ŀ����㣬˵��:��!���������Ȥѽ!\n");
      tell_object(me,"����һ��ͼ�����Ҵ����򵽺ö����貽Ŷ! \n");
      tell_object(me,"�� �׺���������һ��ʧ���Ծõ���������˵....\n");
      return "......\n";
}

